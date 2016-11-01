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
    public array<string> $path = array(); // api/path/
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
        $this->type = ContentType::assert( $this->headers->containsKey('Content-Type') ? $this->headers->get("Content-Type") : ContentType::TEXT);
        // -->Get: request method
        $this->method = HttpMethod::assert($this->server->get("REQUEST_METHOD"));
        // -->Get: path
        $this->getCurrentPath();
        // -->Register: Request Handler
        if (class_exists("Opes\Http\Headers\\".$this->method, true)) {
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


            // var_dump($this->request);
            // var_dump($this->server);
            // var_dump(getallheaders());
        }
    }

    /*
        getCurrentPath:: get current API path
    */
    private function getCurrentPath(): void {
        if ($this->server->containsKey('PATH_INFO')) {
            $this->path = explode('/', (string) $this->server->get('PATH_INFO'));
            array_shift($this->path);
        }
    }

}
