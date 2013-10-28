<?php

$basedir = 'problems';
$a = 'gcc -lm -o ' .$basedir . '/' . $argv[2] . ' problems/' .  $argv[1];

exec($a);

