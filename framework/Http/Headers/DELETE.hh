<?hh //strict

namespace Opes\Http\Headers;
/**
  HEADER: DELETE
  -- Map the delete values into $this->delete
  -- Parse $server accordingly

*/

use Opes\Http\Headers\RequestHeader;
use \Opes\Http\{
  ContentType,
  HttpMethod
};

class DELETE extends RequestHeader {
  use HttpHeader;

  public HttpMethod $method = HttpMethod::DELETE;

  public function __construct(
    Map<string,mixed> $server,
    ContentType $type = ContentType::JSON,
    public Map<string, mixed> $post = Map{},
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
