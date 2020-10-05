class LFUCache {
  class Node {
    int key;
    int value;

    int count;

    Node prev;
    Node next;

    Node(int key, int value) {
      this.key = key;
      this.value = value;
    }

    void addAfter(Node node) {
      node.prev = this;
      next = node;
    }

    void remove() {
      if (next != null) {
        next.prev = prev;
      }

      if (prev != null) {
        prev.next = next;
      }
    }
  }

  int maxSize;
  int size;

  Map < Integer,
  LinkedList < Node >> counter;
  Map < Integer,
  Node > nodeMap;

  Node head;
  Node tail;

  int minCount;

  public LFUCache(int capacity) {
    maxSize = capacity;
    minCount = 0;
    size = 0;

    counter = new HashMap < >();
    nodeMap = new HashMap < >();

    head = null;
  }

  public int get(int key) {
    if (!nodeMap.containsKey(key)) {
      return - 1;
    }

    Node node = nodeMap.get(key);

    // remove node from current counter table
    LinkedList < Node > nodes = counter.get(node.count);
    nodes.remove(node);

    // get the first node, node1, from nodes previous count frequency table
    // add node1 after node
    if (nodes.size() > 0) {
      Node node1 = nodes.peekFirst();
      node.addAfter(node1);
      if (node == tail) {
        tail = node1;
      }
    }

    node.count += 1;
    if (!counter.containsKey(node.count)) {
      counter.put(node.count, new LinkedList < >());
    }

    // add node after the last node of update count list
    LinkedList < Node > updatesNodes = counter.get(node.count);
    if (updatesNodes.size() > 0) {
      Node node1 = updatesNodes.peekLast();
      node1.addAfter(node);
      if (node1 == tail) {
        tail = node;
      }
    }

    //add node with updated count to counter table
    updatesNodes.offer(node);

    return node.value;
  }

  // put a value on cache
  public void put(int key, int value) {
    // we cannot put anything on cache if its capacity is zero
    if (maxSize == 0) {
      return;
    }

    // if the key already exists in linked list
    // mark it as recently used
    // and update its value
    if (nodeMap.containsKey(key)) {
      // mark it as recently used
      // increase its use frequency
      get(key);

      // update its value
      Node node = nodeMap.get(key);
      node.value = value;
      return;
    }

    // if we have reached capacity
    // remove the least recently used item
    // the least recently used item will have smallest frequency (same as the node at tail)
    // if x nodes have same frequency as tail, remove the first node, n, from list of x nodes (least recently used)
    // after removing n from the list, remove n from nodeMap table and  counter table        
    if (size == maxSize) {
      int count = tail.count;
      Node node = counter.get(count).pollFirst();
      // remove node from linked list
      remove(node);

      // remove node from nodes table
      nodeMap.remove(node.key);

      //remove node from counter table
      counter.get(node.count).remove(node);
    }

    // add node to the end of linked list
    Node node = addToTail(key, value);

    // add it nodeMap table
    nodeMap.put(key, node);

    if (!counter.containsKey(node.count)) {
      counter.put(node.count, new LinkedList < >());
    }

    // add it to counter table
    counter.get(node.count).offer(node);
  }

  // remove a node from linked list
  void remove(Node node) {
    node.remove();

    if (head == node) {
      head = head.next;
      if (head != null) {
        head.prev = null;
      }
    }

    if (tail == node) {
      tail = node.prev;
    }

    size--;
  }

  // add a node to end of linked list
  Node addToTail(int key, int value) {
    Node node = new Node(key, value);

    if (head == null) {
      head = node;
      tail = head;
    } else {
      tail.addAfter(node);
      tail = node;
    }

    size++;

    return node;
  }
}
