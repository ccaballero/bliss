<?php

defined('APP_PATH')
    || define('APP_PATH', realpath(dirname(__FILE__) . '/..'));

class Config {

    public $c_compiler = 'gcc -lm -o %s %s > /dev/stdout 2> /dev/stdout';
    public $cpp_compiler = 'g++ -lm -o %s %s > /dev/stdout 2> /dev/stdout';

    public $java_compiler =<<<BEGIN
if [ ! -d "%s" ]; then
    mkdir %s;
fi
javac -d %s %s > /dev/stdout 2> /dev/stdout
BEGIN;

    public $time_limit = '2'; // in seconds
    public $memory_limit = '1024'; // in kbytes

    public $run_script = 'run.sh %s %s %s %s';

    public $dir_bin;
    public $dir_input;
    public $dir_output;
    public $dir_problems;

    public function __construct() {
        $this->run_script = APP_PATH . '/lib/' . $this->run_script;

        $this->dir_bin = APP_PATH . '/data/bin';
        $this->dir_input = APP_PATH . '/data/input';
        $this->dir_output = APP_PATH . '/data/output';
        $this->dir_problems = APP_PATH . '/data/problems';
    }
}
