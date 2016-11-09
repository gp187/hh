<?hh //decl
// -->Start: the framework
require __DIR__.'/../framework/Start.hh';

// -->Register: controllers
use Opes\Http\Request as Request;
use Opes\UAC\User as User;

// var_dump(getallheaders());
// var_dump($_GET);
// var_dump($_POST);
// var_dump($_REQUEST);

// -->Register: the app
$app = new Request();
// -->Parse: the headers
$app->parseRequest($_SERVER, $_COOKIE, $_GET, $_POST, $_FILES);

// TODO
// 1) parse server
    // - order paths by request header
    // - loop paths from there only





echo "<br>Request:-------------<br>";
// var_dump($app->response);
echo "<br>";
// var_dump($app->server);
echo "<br>";
echo "<br>Path:";
// var_dump($app->path);
echo "<br>";
echo "<br>";
