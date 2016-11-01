<?hh //strict

namespace Opes\Http\Headers;
/**
  HEADER: PUT
  -- Map the put values into $this->put
  -- Parse $server accordingly

*/

use Opes\Http\Headers\RequestHeader;
use \Opes\Http\{
  ContentType,
  HttpMethod
};

class PUT extends RequestHeader {
  use HttpHeader;

  public HttpMethod $method = HttpMethod::PUT;

  public function __construct(
    Map<string,mixed> $server,
    ContentType $type = ContentType::JSON,
    public Map<string, mixed> $post = Map{},
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
