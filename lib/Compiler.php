<?php

class Compiler
{
    public static function compile($filename, $config) {
        $split = explode('.', $filename);
        $extension = array_pop($split);
        $name = implode('.', $split);

        switch ($extension) {
            case 'c':
                Compiler::compileC($name, $config);
            case 'java':
                Compiler::compileJava($name, $config);
        }
    }

    public static function compileC($name, $config) {
        $a = sprintf($config->c_compiler,
            $config->dir_bin . '/' . $name,
            $config->dir_problems . '/' . $name . '.c'
        );

        exec($a);
    }

    public static function compileJavac() {
        
    }
}
