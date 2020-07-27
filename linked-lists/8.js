/**
 * 8.js
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements a priority queue abstraction
 *
 * Ashen Gunaratne
 * mail@ashenm.ml
 *
 */

'use strict';

class Node {

  constructor (value, priority, next=null) {
    this.value = value;
    this.priority = priority;
    this.next = next;
  }

}

class LinkedList {

  constructor (head=null) {
    this.head = head;
  }

  // conjoins a new node
  insert (value, priority) {

    let elect;
    let previous;

    const inset = new Node(value, priority);

    if (!this.head) {
      return this.head = inset, this;
    }

    elect = this.head;

    while (elect) {

      if (elect.priority < priority) {
        break;
      }

      previous = elect;
      elect = elect.next;

    }

    inset.next = elect;

    if (!previous) {
      return this.head = inset, this;
    }

    previous.next = inset;

    return this;

  }

  // removes the highest priority node
  serve () {

    const elect = this.head;

    if (!elect) {
      return elect;
    }

    this.head = elect.next;

    return elect;

  }

  // returns the highest priority node
  peak () {
    return this.head;
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

  list.insert(25, 20);
  list.insert(50, 30);
  list.insert(75, 25);

  console.log(list.range());
  console.log(JSON.stringify(list.peak()));

  list.serve();

  for (let elect = list.head; elect; elect = elect.next) {
    console.log(elect.value);
  }

};

if (require.main === module) {
  main();
}

// vim: set expandtab shiftwidth=2:
