<?hh //strict

/**
  HEADER: DELETE
  -- Map the delete values into $this->delete
  -- Parse $server accordingly

*/
namespace Opes\Http\Headers;

use Opes\Http\Headers\RequestHeader;

class DELETE extends RequestHeader {
  use HttpHeader;

  public string $method = "DELETE";

  public function __construct(
    Map<string,mixed> $server,
    string $type = "",
    public Map<string,mixed> $delete = Map{}
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
