<?hh //strict

namespace Opes\Http {


/**
 *  Router:: get all the defined routes and match them with $callbacks
 *
 */

enum HttpMethod: string {
    GET = "GET";
    POST = "POST";
    PUT = "PUT";
    PATCH = "PATCH";
    DELETE = "DELETE";
}


type settings = shape(
     'prefix' => string,
     'component' => string
   );

type route = shape(
    'path' => string,
    'method' => HttpMethod,
    'component' => \Opes\Base\TController,
    'controller' => string
  );
const string DS = '/';


final class Router{
  public static Map<string,route> $routes = Map{};
  public static Set<string> $prefixes = Set{};
  public static Set<string> $paths = Set{};
  private static ImmMap<string,string> $defaults = ImmMap{
    'prefix' => 'api/v1'
  };

  /*
      addZone :: add routing zone to the current route list
  */
  public static function addZone(string $slug, ImmMap <string,route> $r, settings $o): bool{
      // -->Set: route
      $routes = Map{};
      $prefix = DS.Shapes::idx($o, 'prefix', self::$defaults->get('prefix'));
      if (!self::$prefixes->contains($prefix)) self::$prefixes->add($prefix.DS);
      // -->Iterate
      $iterator = $r->getIterator();
      // -->Loop
      while($iterator->valid()) {
          // -->Add: full path
          $key = $slug.DS.$iterator->key();
          self::$paths->add($key);
          // -->Make: route object
          self::$routes->add(Pair{(string) $key, $iterator->current() });
          // -->Next
          $iterator->next();
      }
      return true;
  }

  /*
    validateRoute :: get current route and see if you can find an associated function
  */
  public static function routeExists(string $route): ?route {
      $return = null;
      $requestRoute = Set{};

      // -->Match: the current prefix to one of the authorized ones
      $it = self::$prefixes->getIterator();
      while($it->valid()) {
          if (startsWith($route, $it->current())) {
              $requestRoute = new Set(explode(DS, (string) str_replace($it->current(), "", $route)));
              break;
          }
          $it->next();
      }
      if (!$requestRoute) return null;

      // -->Match: match the route's first value and eliminate what others don't match
      $it = self::$routes->getIterator();
      while ($it->valid()) {
          $serverRoute = new Set(explode(DS, $it->key()));

          $itt = $requestRoute->getIterator();
          while ($itt->valid()) {
              if (!self::routeEquals($itt->current(),(string) $serverRoute->firstValue())) break;
              $serverRoute = $serverRoute->skip(1);
              // if this is the last in the server route, then we gotti
              if ($itt->current() == $requestRoute->lastValue())
                  return $it->current();
              $itt->next();
          }
          $it->next();
      }
      return $return;
  }
  // -->Set: options
  public static function options(settings $r) : void{

  }

  private static function routeEquals(string $declaredRoute, string $incommingRoute): bool {
       return (substr($declaredRoute, 0, 1) == '@') ? true : ($declaredRoute == $incommingRoute);
  }
}
}
