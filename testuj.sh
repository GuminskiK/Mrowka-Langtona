#!/bin/bash

compareTestResults() {
    test_in_dir=$1
    test_out_dir=$2

    # Jeżeli brak pliku wyjściowego, to każde wyjście jest poprawne
    if [[ ! -f "$test_in_dir/output" ]]
    then
      rm -f "$test_out_dir/output"
    fi

    diff --recursive --brief "$test_in_dir" "$test_out_dir" &> /dev/null

    return $?
}

correct=0
done=0
errors=""


temp_dir=$(mktemp --directory)
project_dir=$(readlink -f "$0")
project_dir=$(dirname "$project_dir")
tests_dir=$project_dir/testy
mrowka_bin="$project_dir/bin/mrowka"
start_pwd=$(pwd)
clear_line="\r\033[K"

for i in "$tests_dir"/*
do
  done=$((done+1))
  test_id=$(basename $i)

  test_dir=$temp_dir/$test_id
  test_in_dir=$tests_dir/$test_id

  args=$(cat "$test_in_dir/args")

  cp -r "$test_in_dir" "$test_dir"
  cp "$mrowka_bin" "$test_dir/mrowka"

  cd "$test_dir" || exit 1
  ./mrowka $args < "input" &> "$test_dir/output"
  rm -f mrowka

  printf "${clear_line}Test %s (%i/%i)" "$test_id" $correct $done
  compareTestResults "$test_in_dir" "$test_dir"
  if [ $? -eq 0 ]
  then
    correct=$((correct+1))
  else
    errors="$errors $test_id"
  fi
done
cd "$start_pwd" || exit 1

if [ $correct -eq $done ]
then
  printf "${clear_line}Wszystkie testy zaliczone\n"
  exit 0
else
  printf "${clear_line}Zaliczono %i/%i testow\n" $correct $done

  printf "Nie zaliczone testy: %s\n" "$errors"

  printf "Katalog tymczasowy: %s\n" "$temp_dir"

  exit 1
fi