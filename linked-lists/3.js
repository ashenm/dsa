/**
 * 3.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements an abstract manipulation method
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

  let head = null;

  head = append(head, 25);
  head = append(head, 50);

  for (let elect = head; elect !== null; elect = elect.next) {
    console.log(elect.value);
  }

};

const append = function (head, value) {

  const inset = new Node(value);

  if (!head) {
    return inset;
  }

  let elect = head;

  while (elect.next !== null) {
    elect = elect.next;
  }

  elect.next = inset;

  return head;

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
