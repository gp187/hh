<?hh //strict

/*
  Request Headers Parent
    -- extends all Headers to parse the shit out of them
    -- header trait for self-parsing

*/
namespace Opes\Http\Headers;

use \Opes\Http\{
  ContentType,
  HttpMethod
};

class RequestHeader {
  // parent of all requests
}


trait HttpHeader {
    public Map<string,mixed> $json = Map{};
    public ContentType $type = ContentType::JSON;

    /*
        parsePayload:: parse the data by type of header that I find in it
    */
    private function parsePayload(ContentType $type): bool {
        // -->Set: type of data: json, from, xml....
        //$this->type = $type;
        // -->ContentType: check if json
        switch ($this->type) {
          case ContentType::JSON:
              $this->json = json_decode(file_get_contents('php://input'),true);
              if (json_last_error() !== JSON_ERROR_NONE) die("Cannot parse json data from this shit!");
            break;
          case ContentType::XML:
              // TODO:: process XML -- neah
            break;
          case ContentType::FORM:
              // TODO:: process form ?data
            break;
          case ContentType::TEXT:
              // TODO:: process text ?data
            break;
        }
        return false;
    }
}
