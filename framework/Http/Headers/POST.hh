<?hh //strict

namespace Opes\Http\Headers;
/**
  HEADER: POST
  -- Map the post values into $this->post
  -- Parse $server accordingly

*/

use Opes\Http\Headers\RequestHeader;
use \Opes\Http\{
  ContentType,
  HttpMethod
};

class POST extends RequestHeader {
  use HttpHeader;

  public HttpMethod $method = HttpMethod::POST;

  public function __construct(
    Map<string,mixed> $server,
    ContentType $type = ContentType::JSON,
    public Map<string, mixed> $post = Map{},
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
