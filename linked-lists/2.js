/**
 * 2.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Demonstrates linked list itteration
 *
 * Ashen Gunaratne
 * mail@ashenm.ml
 *
 */

'use strict';

class Node {

  constructor (value, next=null) {
    this.value = value;
    this.next = next;
  }

}

const main = function () {

  const y = new Node(50);
  const x = new Node(25, y);

  for (let n = x; n !== null; n = n.next) {
    console.log(n.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
