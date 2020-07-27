/**
 * 10.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements a double-ended queue
 *
 * Ashen Gunaratne
 * mail@ashenm.ml
 *
 */

'use strict';

class Node {

  constructor (value, prev=null, next=null) {
    this.prev = prev;
    this.value = value;
    this.next = next;
  }

}

class LinkedList {

  constructor (head=null, tail=null) {
    this.head = head;
    this.tail = tail;
  }

  // removes the rightmost node
  pop () {

    const elect = this.tail;

    if (!elect) {
      return elect;
    }

    this.tail = this.tail.prev;

    if (this.tail) {
      this.tail.next = null;
    }

    return elect;

  }

  // removes the leftmost node
  shift () {

    const elect = this.head;

    if (!elect) {
      return elect;
    }

    this.head = this.head.next;

    if (this.head) {
      this.head.prev = null;
    }

    return elect;

  }

  // conjoins a node to left
  unshift (value) {

    const inset = new Node(value, null, this.head);

    if (!this.head) {
      return this.head = this.tail = inset, this;
    }

    this.head.prev = inset;
    this.head = inset;

    return this;

  }

  // conjoins a node to right
  push (value) {

    const inset = new Node(value, this.tail);

    if (!this.tail) {
      return this.head = this.tail = inset, this;
    }

    this.tail.next = inset;
    this.tail = inset;

    return this;

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

  list.push(50);
  list.unshift(25);
  list.push(75);

  console.log(list.range());

  list.shift();
  list.pop();

  for (let elect = list.head; elect; elect = elect.next) {
    console.log(elect.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
