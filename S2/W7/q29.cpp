Set& operator+(const Set& set) {
    	Set *s = new Set(*this);
    	s->add(set);
    	return *s;
    }
Set& operator-(const Set& set) {
	Set *s = new Set;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < set.count; j++) {
			if (element[i] == set.element[j]) {
				s->element[s->count++] = element[i];
				break;
			}
		}
	}
	return *s;
}
