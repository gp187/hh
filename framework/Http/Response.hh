<?hh //strict
/*
    Response:: this is the response object that maps the $controller with the function and calls it
*/
namespace Opes\Http {

final class Response {

    public function __construct(
      public ?route $route
    ): void {
        $this->execute();
    }
    // -->Execute: the incomming request
    public function execute(): void {
        echo "------------<br>";
        var_dump($this->route);
        echo "------------<br>";


        $call = meth_caller(
          '\Opes\UAC\User',
          'list'
        );
        $c = new \Opes\UAC\User();

        var_dump($call($c));
        // $call = class_meth(
        //   $this->route['component'],
        //   $this->route['controller']
        // );



        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function
        // TODO: run the current route by controller and function

    }
    // -->JSON: format output to JSON
    public function json(): string {

        return '{}';
    }
}
}
