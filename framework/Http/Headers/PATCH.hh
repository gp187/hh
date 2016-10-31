<?hh //strict

/**
  HEADER: PATCH
  -- Map the patch values into $this->patch
  -- Parse $server accordingly

*/
namespace Opes\Http\Headers;

use Opes\Http\Headers\RequestHeader;

class PATCH extends RequestHeader {
  use HttpHeader;
  
  public string $method = "PATCH";

  public function __construct(
    Map<string,mixed> $server,
    string $type = "",
    public Map<string, mixed> $patch = Map{}
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
