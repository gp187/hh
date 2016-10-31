<?hh //strict

namespace Opes\Http;

/**
 *  Router:: get all the defined routes and match them with $callbacks
 *
 */

type root = shape('root' => string);
type route = shape('path' => string);

class Router{
  public Map<string,mixed> $routes = Map{};


  public function __construct(){
    # code...
  }
  public static function addZone(Map<string,mixed> $r) : void{

      var_dump($r);

  }
  public static function updateZone(Map<string,mixed> $r) : void{

  }
  public static function removeZone(Map<string,mixed> $r) : void{

  }
  // -->Set: options
  public static function options(Map<string,mixed> $r) : void{

  }
}
