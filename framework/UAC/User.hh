<?hh //strict
/**
  UserAccessControl
    Start a user for no reason

*/
namespace Opes\UAC;


final class User extends \Opes\Base\WebController {
    public Map<string,mixed> $access = Map{};

    // public function __construct(): void {
    //     // -->Set: inital access
    //     $this->access = new Map([
    //       'headers' => ['GET','PUT','POST','PATCH','DELETE']
    //     ]);
    // }

    public function list(): string {
        return "<br><br>You fucking did it!";
        // die("<br><br>You fucking did it!");
        // die("<br><br>You fucking did it!");
        // die("<br><br>You fucking did it!");
    }

    public function profile(string $userId): void {

    }
}
