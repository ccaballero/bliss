<?php

class Validator {

    public static function validate($filename, $config) {
        $split = explode('.', $filename);
        $extension = array_pop($split);
        $name = implode('.', $split);

        $_file = $config->dir_bin . '/' . $name . '/' . $name;

        $err1 = file_get_contents($_file . '.err.1');
        $err2 = file_get_contents($_file . '.err.2');
        $time = file_get_contents($_file . '.time');
        $out = file_get_contents($_file . '.out');
        
        if (preg_match('/^TIMEOUT .*$/', $err1)) {
            return 'time limit exceeded';
        } else if (preg_match('/^MEM .*$/', $err2)) {
            return 'memory limit exceeded';
        } else {
            // wrong answer validation
            echo $time . PHP_EOL;
        }
    }
}
