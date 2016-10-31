<?hh //strict
/**
  Request $_SERVER data parser
    -- prepare the request object and route the paths

*/
namespace Opes\Http;
use Opes\Http\Headers\GET as GET;
use Opes\Http\Headers\POST as POST;
use Opes\Http\Headers\PUT as PUT;
use Opes\Http\Headers\PATCH as PATCH;
use Opes\Http\Headers\DELETE as DELETE;


class Request {
    public Map<string,mixed> $server = Map{};
    public Map<string,mixed> $headers = Map{};
    public array<string> $path = array(); // api/path/
    public string $method = ""; // GET, PUT, POST, DELETE, PATCH
    public string $type = ""; // raw, json, xml
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
        $this->detectRequestType();
        // -->Get: path
        $this->getCurrentPath();
        // -->Get: request method
        $this->method = (string) $this->server->get("REQUEST_METHOD");
        // -->Register: Request Handler
        if (class_exists("Opes\Http\Headers\\".$this->method, true)) {
            // -->Register: request object and associated data
            switch ($this->method) {
              case 'GET':

                  $this->request = new GET($this->server, new Map($get));
                break;
              case 'POST':

                  $this->request = new POST($this->server, $this->type, new Map($post));
                break;
              case 'PUT':

                  $this->request = new PUT($this->server, $this->type, new Map($post));
                break;
              case 'PATCH':

                  $this->request = new PATCH($this->server, $this->type, new Map($post));
                break;
              case 'DELETE':

                  $this->request = new DELETE($this->server, $this->type, new Map($post));
                break;
              default:
                  // TODO :: return response header with 500 because of wrong header sent

                break;
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
    /*
        detectRequestType:: detect the type of incomming data
    */
    private function detectRequestType() : bool {
        // -->Set: allowed data types
        $contentType = (string) $this->headers->get("Content-Type");
        $allowedType = array(
            'application/json' => 'json',
            'application/xml' => 'xml',
            'application/x-www-form-urlencoded' => 'form',
            'text/plain' => 'text',
            '' => 'text'
        );
        // -->Set: current dataRequest type
        $this->type = $allowedType[$contentType];
        if (!$this->type)
            die("Header named ".$contentType." cannot be processed");

        return !!$this->type;
    }

}
