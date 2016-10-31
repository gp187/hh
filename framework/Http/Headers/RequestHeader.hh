<?hh //strict

/**
  Request Headers Parent
    -- extends all Headers to parse the shit out of them
    -- header trait for self-parsing

*/
namespace Opes\Http\Headers;


class RequestHeader {

}


trait HttpHeader {
    public Map<string,mixed> $json = Map{};
    public string $type = "";

    /*
        parsePayload:: parse the data by type of header that I find in it
    */
    private function parsePayload(string $type): bool {
        // -->Set: type of data: json, from, xml....
        $this->type = $type;
        // -->ContentType: check if json
        switch ($type) {
          case 'json':
              if (!$this->parseRequestJSON()) die("Cannot parse json data from this shit!");
            break;
          case 'xml':
              // TODO:: process XML -- neah
            break;
          case 'form':
              // TODO:: process form ?data
            break;
          case 'text':
              // TODO:: process text ?data
            break;
          default:
              die("Unknown or Unallowed content type received");
            break;
        }
        return false;
    }

    /*
        parseRequestJSON:: parse json from request stream
    */
    private function parseRequestJSON() : bool {
        $this->json = json_decode(file_get_contents('php://input'),true);
        return (json_last_error() === JSON_ERROR_NONE);
    }

    /*
        isValidJSON:: validate json string
    */
    public function isValidJSON(string $str) : bool {
        json_decode($str);
        return (json_last_error() === JSON_ERROR_NONE);
    }
}
