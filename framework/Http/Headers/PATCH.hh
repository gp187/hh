<?hh //strict

namespace Opes\Http\Headers;
/**
  HEADER: PATCH
  -- Map the patch values into $this->patch
  -- Parse $server accordingly

*/

use Opes\Http\Headers\RequestHeader;
use \Opes\Http\{
  ContentType,
  HttpMethod
};

class PATCH extends RequestHeader {
  use HttpHeader;

  public HttpMethod $method = HttpMethod::PATCH;

  public function __construct(
    Map<string,mixed> $server,
    ContentType $type = ContentType::JSON,
    public Map<string, mixed> $post = Map{},
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
