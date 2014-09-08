// ----------------------------
// cs371p-collatz/UVaCollatz.c++
// Copyright (C) 2014
// Vaibhav Gupta
// ----------------------------

// --------
// includes
// --------

#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#define BASE 0
#define MAX_SIZE 500000

// -----------
// cache
// -----------
int cache[MAX_SIZE] = {};

// ------------
// cycle_length
// ------------

int cycle_length (unsigned int num) {
  int length = 1;
  while (num != 1) {
    if (num > BASE && num < MAX_SIZE) {
      if (cache[num] != 0) {
        return length + cache[num] - 1;}}
    length += 1 + (num & 0x1);
    num = (num >> 1) + (-(num & 0x1) & (num + 1));}
  return length;}

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
  int i;
  r >> i;
  if (!r)
    return std::make_pair(0, 0);
  int j;
  r >> j;
  return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  int max_val = 0;
  i = std::max(i, j/2 + 1);
  while (i <= j) {
    int len = cycle_length(i);
    if (i > BASE && i < MAX_SIZE) {
      cache[i] = len;}
    max_val = std::max(max_val, len);
    i++;}
  return max_val;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
  w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
  while (true) {
    const std::pair<int, int> p = collatz_read(r);
    if (p == std::make_pair(0, 0))
      return;
    const int i = p.first;
    const int j = p.second;
    const int v = collatz_eval(std::min(i, j), std::max(i, j));
    collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
