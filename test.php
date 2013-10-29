<?php

include 'lib/Config.php';
include 'lib/Compiler.php';

$config = new Config();
$file = $argv[1];

Compiler::compile($file, $config);
