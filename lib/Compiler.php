<?php

class Compiler
{
    public static function compileGCC() {
        $basedir = 'problems';
        $a = 'gcc -lm -o ' .$basedir . '/' . $argv[2] . ' problems/' .  $argv[1];

        exec($a);
        
        return 0;
    }
}
