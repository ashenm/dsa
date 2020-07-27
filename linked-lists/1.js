/**
 * 1.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Creates a single-node linked list
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

  const n = new Node(25);

  console.log(n.value);

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
