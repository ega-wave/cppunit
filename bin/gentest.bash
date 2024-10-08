
# usage : bash gentest.bash class_name

CLASS=$1

cat << EOS | base64 -d | sed 's/\$CLASS\$/'$CLASS'/g'
CiNpbmNsdWRlICJUZXN0Q2FzZS5oIgojaW5jbHVkZSAiVGVzdEFzc2VydEZ1bmN0b3IuaCIKI2lu
Y2x1ZGUgIlRlc3RSZWdpc3Rlci5oIgojaW5jbHVkZSAiVGVzdFN1aXRlLmgiCgojaW5jbHVkZSAi
JENMQVNTJC5oIgoKLyoqCiAqIHRlbXBsYXRlLWNsYXNzIGZvciBFVkVSWSB0ZXN0LWNhc2UuCiAq
IElmIHlvdSBuZWVkLCBkbyBleHBsaWNpdCBzcGVjaWFsaXphdGlvbiBvZiB0aGlzIHRlbXBsYXRl
LWNsYXNzLAogKiAgIGVzcGVjaWFsbHkgdGhyZWUgbWV0aG9kcyAoc2V0VXAoKSwgcnVuVGVzdCgp
LCBhbmQgdGVhckRvd24oKSkuCiAqLwp0ZW1wbGF0ZSA8VGVzdENhc2U6OnNpemVfdHlwZSBOPgpj
bGFzcyAkQ0xBU1MkVGVzdCA6IHB1YmxpYyBUZXN0Q2FzZQp7CnB1YmxpYzoKICB0eXBlZGVmIFRl
c3RDYXNlOjpzaXplX3R5cGUgc2l6ZV90eXBlOwoKICBleHBsaWNpdCAkQ0xBU1MkVGVzdChjb25z
dCBjaGFyKiB0ZXN0bmFtZSkgOiBUZXN0Q2FzZShOLCB0ZXN0bmFtZSkge30KICB2aXJ0dWFsIH4k
Q0xBU1MkVGVzdCgpIHt9CgogIHZpcnR1YWwgdm9pZCBzZXRVcCgpIHt9CiAgdmlydHVhbCB2b2lk
IHJ1blRlc3QoKSB7fQogIHZpcnR1YWwgdm9pZCB0ZWFyRG93bigpIHt9Cgpwcml2YXRlOgogICRD
TEFTUyRUZXN0KCk7CiAgJENMQVNTJFRlc3QoY29uc3QgJENMQVNTJFRlc3QmKTsKICAkQ0xBU1Mk
VGVzdCYgb3BlcmF0b3I9KGNvbnN0ICRDTEFTUyRUZXN0Jik7Cn07CgoKLy8gSWYgeW91IG5lZWQs
IGltcGxlbWVudCBleHBsaWNpdCBzcGVjaWFsaXphdGlvbiBvZiAkQ0xBU1MkVGVzdDxOPjo6c2V0
VXAoKS4KLyoKdGVtcGxhdGUgPD4Kdm9pZAokQ0xBU1MkVGVzdDwxPjo6c2V0VXAoKQp7Cn0KKi8K
CnRlbXBsYXRlIDw+CnZvaWQKJENMQVNTJFRlc3Q8MT46OnJ1blRlc3QoKQp7CiAgVEVTVF9BU1NF
UlRfRVFVQUxTKDAsKGludClMZWFwOjokQ0xBU1MkPDE+Ojp2YWx1ZSk7Cn0KCgovLyBJZiB5b3Ug
bmVlZCwgaW1wbGVtZW50IGV4cGxpY2l0IHNwZWNpYWxpemF0aW9uIG9mICRDTEFTUyRUZXN0PE4+
Ojp0ZWFyRG93bigpLgovKgp0ZW1wbGF0ZSA8Pgp2b2lkCiRDTEFTUyRUZXN0PDE+Ojp0ZWFyRG93
bigpCnsKfQoqLwoKLyoqCiAqIHJldHVybiBhIFRlc3RTdWl0ZSBvZiBUZXN0Q2FzZTwxPiwgVGVz
dENhc2U8Mj4sIC4uLiwgYW5kIFRlc3RDYXNlPE4+CiAqLwpzdGF0aWMgVGVzdCogc3VpdGUoKQp7
CiAgVGVzdFN1aXRlKiBzdWl0ZSA9IG5ldyBUZXN0U3VpdGUoIiIpOwoKICBzdWl0ZS0+YWRkVGVz
dChuZXcgJENMQVNTJFRlc3Q8MT4oIiIpKTsKCiAgcmV0dXJuIHN1aXRlOwp9CnN0YXRpYyBUZXN0
UmVnaXN0ZXIgc3RhdGljX2xvY2FsX3JlZ2lzdGVyKHN1aXRlKTsKCg==
EOS

