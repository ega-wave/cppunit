
# usage : bash gentest.bash class_name

CLASS=$1

cat << EOS | base64 -d | sed 's/\$CLASS\$/'$CLASS'/g' #> ${CLASS}Test.cpp
CiNpbmNsdWRlICJUZXN0Q2FzZS5oIgojaW5jbHVkZSAiVGVzdEFzc2VydEZ1bmN0b3IuaCIKI2lu
Y2x1ZGUgIlRlc3RSZWdpc3Rlci5oIgojaW5jbHVkZSAiVGVzdFN1aXRlLmgiCgovLyA844Om44O8
44K254us6Ieq44Gu44Kk44Oz44Kv44Or44O844OJPgojaW5jbHVkZSAiJENMQVNTJC5oIgpjbGFz
cyAkQ0xBU1MkRnJpZW5kCnsKcHVibGljOgp9OwovLyA8L+ODpuODvOOCtueLrOiHquOBruOCpOOD
s+OCr+ODq+ODvOODiT4KCi8qKgogKiDlgIvjgIXjga7jg4bjgrnjg4jjgrHjg7zjgrnjga7pm5vl
novvvIjjg4bjg7Pjg5fjg6zjg7zjg4jvvIkuCiAqIOWQhOODhuOCueODiOOCseODvOOCueOBruio
mOi/sOOBr+OAgeOBk+OBruODhuODs+ODl+ODrOODvOODiOOBrueJueauiuWMluOBqOOBhOOBhuW9
ouOBp+ihjOOBhi4KICovCnRlbXBsYXRlIDxUZXN0Q2FzZTo6c2l6ZV90eXBlIE4+CmNsYXNzICRD
TEFTUyRUZXN0IDogcHVibGljIFRlc3RDYXNlLCBwdWJsaWMgJENMQVNTJEZyaWVuZAp7CnB1Ymxp
YzoKICB0eXBlZGVmIFRlc3RDYXNlOjpzaXplX3R5cGUgc2l6ZV90eXBlOwoKICBleHBsaWNpdCAk
Q0xBU1MkVGVzdChjb25zdCBjaGFyKiB0ZXN0bmFtZSkKICA6IFRlc3RDYXNlKE4sIHRlc3RuYW1l
KSB7fQogIHZpcnR1YWwgfiRDTEFTUyRUZXN0KCkge30KCiAgdmlydHVhbCB2b2lkIHNldFVwKCkg
e30KICB2aXJ0dWFsIHZvaWQgcnVuVGVzdCgpIHt9CiAgdmlydHVhbCB2b2lkIHRlYXJEb3duKCkg
e30KCnByaXZhdGU6CiAgJENMQVNTJFRlc3QoKTsKICAkQ0xBU1MkVGVzdChjb25zdCAkQ0xBU1Mk
VGVzdCYpOwogICRDTEFTUyRUZXN0JiBvcGVyYXRvcj0oY29uc3QgJENMQVNTJFRlc3QmKTsKCi8v
ICAkQ0xBU1MkKiBmaXh0dXJlXzsKfTsKCi8vIOODhuOCueODiOOCseODvOOCuShydW5UZXN0KCkp
44Gv44GT44GT44Gr6KiY6L+w44GZ44KLCi8vIHNldFVwKCksIHRlYXJEb3duKCnjga/mm7jjgYvj
garjgZHjgozjgbDjg4fjg5Xjgqnjg6vjg4jvvIjkvZXjgoLjgZfjgarjgYTvvInjga7li5XkvZzj
gpLjgZnjgosKLyoKdGVtcGxhdGUgPD4Kdm9pZAokQ0xBU1MkVGVzdDwxPjo6c2V0VXAoKQp7Cn0K
Ki8KdGVtcGxhdGUgPD4Kdm9pZAokQ0xBU1MkVGVzdDwxPjo6cnVuVGVzdCgpCnsKICBURVNUX0FT
U0VSVF9FUVVBTFMoMCwoaW50KUxlYXA6OiRDTEFTUyQ8MT46OnZhbHVlKTsKfQovKgp0ZW1wbGF0
ZSA8Pgp2b2lkCiRDTEFTUyRUZXN0PDE+Ojp0ZWFyRG93bigpCnsKfQoqLwovLyDjgZPjgozjgojj
gorkuIvjgaflrp/ooYzjgZnjgovjg4bjgrnjg4jjgrHjg7zjgrnjgpLov73liqDjgZnjgosKLyoq
CiAqIOOBk+OBruODleOCoeOCpOODq+OBp+iomOi/sOOBleOCjOOBpuOBhOOCi+ODhuOCueODiOOC
seODvOOCueOBrumbhuWQiOOCkui/lOOBmS4KICovCnN0YXRpYyBUZXN0KiBzdWl0ZSgpCnsKICBU
ZXN0U3VpdGUqIHN1aXRlID0gbmV3IFRlc3RTdWl0ZSgiIik7CgogIHN1aXRlLT5hZGRUZXN0KG5l
dyAkQ0xBU1MkVGVzdDwxPigiIikpOwoKICByZXR1cm4gc3VpdGU7Cn0Kc3RhdGljIFRlc3RSZWdp
c3RlciBzdGF0aWNfbG9jYWxfcmVnaXN0ZXIoc3VpdGUpOwoK
EOS

