# Aufgabe 1
l = [
  ('a', 1),
  ('b',2 )
]
l.append(('c', 3))
print(l)
d = {
    a:b for a,b in l
}
print(f"Der Buchstabe a hat den Index {d['a']}")
#---
# Aufgabe 2
alphabet = ['a','b','c','c','d','e','e']
alphabet.remove('c')
if not 'f' in alphabet:
    alphabet[-1] = 'f'
print(alphabet)
a,b = alphabet[:2]
print(a,b)
