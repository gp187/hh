<?hh //strict

/**
  HEADER: PUT
  -- Map the put values into $this->put
  -- Parse $server accordingly

*/
namespace Opes\Http\Headers;

use Opes\Http\Headers\RequestHeader;

class PUT extends RequestHeader {
  use HttpHeader;

  public string $method = "PUT";

  public function __construct(
    Map<string,mixed> $server,
    string $type = "",
    public Map<string, mixed> $put = Map{}
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
