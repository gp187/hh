<?hh //strict

/**
  HEADER: POST
  -- Map the post values into $this->post
  -- Parse $server accordingly

*/
namespace Opes\Http\Headers;

use Opes\Http\Headers\RequestHeader;

class POST extends RequestHeader {
  use HttpHeader;

  public string $method = "POST";

  public function __construct(
    Map<string,mixed> $server,
    string $type = "",
    public Map<string, mixed> $post = Map{},
  ): void {
      // -->Parse: data by header type
      $this->parsePayload($type);
  }
}
