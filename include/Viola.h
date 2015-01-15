#ifndef VIOLA_H
#define VIOLA_H

#define GET_MACRO(_1,_2,NAME,...) NAME

#define String(s) $(String, s)
#define Char(c) $(Char, c)

var Symbol(char* str) {
    var charArray = new(Array, Char);
    for (int i = 0; str[i] != 0; i++) {
        push(charArray, Char(str[i]));
    }
    return charArray;
}

#define Int(i) $(Int, i)
#define Real(r) $(Real, r)
#define Dictionary() new(Dictionary)
#define Map() new(Map)
#define Reference(r) $(Reference, r)
#define FileN(name, perm) new(File, name, perm)
#define FileO(n) $(File, n)
#define File(...) GET_MACRO(__VA_ARGS__, FileN, FileO)
#define Table(k, v) new(Table, k, v)
#define Tree(k, v) new(Tree, k, v)
#define List(...) new(List, __VA_ARGS__)
#define Array(t) new(Array, t)
#define Strings(...) List(__VA_ARGS__)
#define Ints(...) List(__VA_ARGS__)
#define Reals(...) List(__VA_ARGS__)
#define Chars(...) List(__VA_ARGS__)
#define Mutex() new(Mutex)
#define Thread() new(Thread)
#define Pool() new(Pool)

#define function var
#define namespace(name, members) \
	typedef struct {\
		members\
	} VIOLA__##name; VIOLA__##name name;

#define let __attribute__((cleanup(free_stack))) var

__attribute__((always_inline))
inline void free_stack(var* ptr) {
	delete(*ptr);
}

#endif
