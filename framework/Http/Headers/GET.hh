<?hh //strict

namespace Opes\Http\Headers;
/**
  HEADER: GET
  -- Map the get values into $this->get
  -- Parse $server accordingly

*/

use Opes\Http\Headers\RequestHeader;
use \Opes\Http\{
  ContentType,
  HttpMethod
};

class GET extends RequestHeader {
  use HttpHeader;

  public HttpMethod $method = HttpMethod::GET;

  public function __construct(
    Map<string,mixed> $server,
    public Map<string,mixed> $get = Map{},
  ): void {
      // TODO:: -->Parse: server
  }
}
