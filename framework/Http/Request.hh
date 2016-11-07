<?hh //strict
/*
  Request $_SERVER data parser
    -- prepare the request object and route the paths

*/
namespace Opes\Http;
use Opes\Http\Headers\{
  GET, POST, PUT, PATCH, DELETE
};
use Opes\Http\{
  HttpMethod
};


enum ContentType: string {
    JSON = 'application/json';
    XML  = 'application/xml';
    FORM = 'application/x-www-form-urlencoded';
    TEXT = 'text/plain';
}



class Request {
    public Map<string,mixed> $server = Map{};
    public Map<string,mixed> $headers = Map{};
    public string $path = DS; // api/path/
    public HttpMethod $method = HttpMethod::GET; // GET, PUT, POST, DELETE, PATCH
    public ContentType $type = ContentType::JSON; // raw, json, xml
    public mixed $request; // GET(), PUT()...

    public function __construct(
        array<string,mixed> $srv,
        array<string,mixed> $cookie,
        array<string,mixed> $get,
        array<string,mixed> $post,
        array<string,mixed> $files
    ): void {
        // -->Set: server
        $this->server = new Map($srv);
        // -->Set: request headers
        $this->headers = new Map(getallheaders());
        // -->Type: of incomming data
        $this->type = ContentType::assert($this->headers->containsKey('Content-Type') ? $this->headers->get("Content-Type") : ContentType::TEXT);
        // -->Get: request method
        $this->method = HttpMethod::assert($this->server->get("REQUEST_METHOD"));
        // -->Get: path
        $this->parseCurrentRoute();
        // -->Match: path to something in the router
        if (Router::routeExists($this->path)) {
          // -->Register: request object and associated data
          switch ($this->method) {
            case HttpMethod::GET:

                $this->request = new GET($this->server, new Map($get));
              break;
            case HttpMethod::POST:

                $this->request = new POST($this->server, $this->type, new Map($post));
              break;
            case HttpMethod::PUT:

                $this->request = new PUT($this->server, $this->type, new Map($post));
              break;
            case HttpMethod::PATCH:

                $this->request = new PATCH($this->server, $this->type, new Map($post));
              break;
            case HttpMethod::DELETE:

                $this->request = new DELETE($this->server, $this->type, new Map($post));
              break;
            // default:
                // TODO :: return response header with 500 because of wrong header sent

              // break;
          }
        }else
            die("Cannot find route");
    }

    /*
        parseCurrentRoute:: get current API path
    */
    private function parseCurrentRoute(): void {
        // TODO: extra checks on sizes
        if ($this->server->containsKey('PATH_INFO')) {
            $this->path = sanitize((string) $this->server->get('PATH_INFO'));
        }
    }

}
