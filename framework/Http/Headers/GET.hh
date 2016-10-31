<?hh //strict

/**
  HEADER: GET
  -- Map the get values into $this->get
  -- Parse $server accordingly

*/
namespace Opes\Http\Headers;

use Opes\Http\Headers\RequestHeader;

class GET extends RequestHeader {
  use HttpHeader;
  
  public string $method = "GET";

  public function __construct(
    Map<string,mixed> $server,
    public Map<string,mixed> $get = Map{},
  ): void {
      // TODO:: -->Parse: server
  }
}
