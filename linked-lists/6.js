/**
 * 6.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements Stack-like operations
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

class LinkedList {

  constructor (head=null) {
    this.head = head;
  }

  // conjoins a new node
  push (value) {
    return this.head = new Node(value, this.head), this.head;
  }

  // removes the last insert
  pop () {

    const elect = this.head;

    if (elect) {
      this.head = elect.next;
    }

    return elect;

  }

  // computes the node count
  range () {

    let n = 0;
    let elect = this.head;

    while (elect) {
      elect = elect.next;
      n += 1;
    }

    return n;

  }

}

const main = function () {

  const list = new LinkedList();

  list.push(25);
  list.push(50);

  console.log(list.range());

  list.pop();

  for (let elect = list.head; elect; elect = elect.next) {
    console.log(elect.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
