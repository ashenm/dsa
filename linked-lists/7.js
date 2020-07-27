/**
 * 7.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements Queue-like operations
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
  queue (value) {

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

  // removes the firstmost insert
  dequeue () {

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

  list.queue(25);
  list.queue(50);

  console.log(list.range());

  list.dequeue();

  for (let elect = list.head; elect; elect = elect.next) {
    console.log(elect.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
