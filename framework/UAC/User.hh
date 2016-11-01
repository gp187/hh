<?hh //strict
/**
  UserAccessControl
    Start a user for no reason

*/
namespace Opes\UAC;


final class User {
    public Map<string,mixed> $access;

    public function __construct():void {
        // -->Set: inital access
        $this->access = new Map([
          'headers' => ['GET','PUT','POST','PATCH','DELETE']
        ]);
    }

    public function list(): void {

    }

    public function profile(string $userId): void {

    }
}
