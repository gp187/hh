<?hh

function sanitize(string $s): string{
    return (string) $s;
}
function startsWith(string $haystack, string $needle): bool{
     return (substr($haystack, 0, strlen($needle)) === $needle);
}
function endsWith(string $haystack, string $needle): bool{
    return (substr($haystack, -strlen($needle)) === $needle);
}
