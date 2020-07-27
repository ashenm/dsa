/**
 * 5.js
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

class LinkedList {

  constructor (head=null) {
    this.head = head;
  }

  // conjoins a new node
  append (value) {

    const inset = new Node(value);

    if (!this.head) {
      return this.head = inset, this;
    }

    let elect = this.head;

    while (elect.next) {
      elect = elect.next;
    }

    elect.next = inset;

    return this;

  }

}

const main = function () {

  const list = new LinkedList();

  list.append(25);
  list.append(50);

  for (let elect = list.head; elect; elect = elect.next) {
    console.log(elect.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
