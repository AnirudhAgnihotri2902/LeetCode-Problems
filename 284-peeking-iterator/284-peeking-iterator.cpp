class PeekingIterator : public Iterator {
    bool hasPeeked;
    int peekedElem;
public:
	PeekingIterator(const vector<int>& num) : Iterator(num) {
        hasPeeked = false;
	}

	int peek() {
        peekedElem = hasPeeked?peekedElem:Iterator::next();
        hasPeeked = true;
        return peekedElem;
	}

	int next() {
	    int nextElem = hasPeeked?peekedElem:Iterator::next();
	    hasPeeked = false;
	    return nextElem;
	}

	bool hasNext() const {
	    return hasPeeked||Iterator::hasNext();
	}
};