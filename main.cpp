#include <iostream>
#include <string>
#include <ctre.hpp>
int main()
{
    std::string b64_string = "AQAAAAHbeKwnOkETYVtfwtW8JJBIhJiCAafbl3/u5W9z9b9xjLAAAABqRzBEAiApU0jJXbqi4M9n8u2ipEKv99bY3KJ2XQ1c0R2NPwt1gAIgcR2nnkvhO91U2808XPrV9Mnk9wm99rk9uOlORkv66OxBIQKpeXSsR3Id9LTTTaryd+AVsp03epDlRsRC+aMuRDjPYf////9uAAAAAAAAAAD92g4AagoiaG13eWRhIiAtIGhvdyBtdWNoIHdvdWxkIHlvdSBkb25hdGUgYW5vbnltb3VzbHkKCmhvdyB0byBjcmVhdGUgb3duZXJsZXNzIEJUQy9CQ0gvQlNWIGFkZHJlc3Mgd2l0aCBzcGVjaWFsIG1lYW5pbmcKCmFtbmVzaWFAYW1uZXNpYTp+JAphbW5lc2lhQGFtbmVzaWE6fiQgd2dldCAtLXF1aWV0IGh0dHBzOi8vZ2l0aHViLmNvbS9saWJiaXRjb2luL2xpYmJpdGNvaW4tZXhwbG9yZXIvcmVsZWFzZXMvZG93bmxvYWQvdjMuMi4wL2J4LWxpbnV4LXg2NC1xcmNvZGUKYW1uZXNpYUBhbW5lc2lhOn4kIHdnZXQgLS1xdWlldCBodHRwczovL2dpdGh1Yi5jb20vc2lwYS9iZWNoMzIvcmF3L21hc3Rlci9yZWYvcHl0aG9uL3NlZ3dpdF9hZGRyLnB5CmFtbmVzaWFAYW1uZXNpYTp+JCB3Z2V0IC0tcXVpZXQgaHR0cHM6Ly9naXRodWIuY29tL29za3lrL2Nhc2hhZGRyZXNzL2FyY2hpdmUvMS4wLjUudGFyLmd6CmFtbmVzaWFAYW1uZXNpYTp+JCBscyAtbCBieC1saW51eC14NjQtcXJjb2RlIHNlZ3dpdF9hZGRyLnB5IDEuMC41LnRhci5negotcnctci0tci0tIDEgYW1uZXNpYSBhbW5lc2lhICAgIDY0OTQgQXVnIDEyIDE0OjE0IDEuMC41LnRhci5negotcnctci0tci0tIDEgYW1uZXNpYSBhbW5lc2lhIDUwMzc3NjggTWF5IDI2ICAyMDE3IGJ4LWxpbnV4LXg2NC1xcmNvZGUKLXJ3LXItLXItLSAxIGFtbmVzaWEgYW1uZXNpYSAgICA0Mzc2IEF1ZyAxMiAxNDoxMyBzZWd3aXRfYWRkci5weQphbW5lc2lhQGFtbmVzaWE6fiQgdGFyIHhmIDEuMC41LnRhci5negphbW5lc2lhQGFtbmVzaWE6fiQgY2htb2QgK3ggYngtbGludXgteDY0LXFyY29kZQphbW5lc2lhQGFtbmVzaWE6fiQgYWxpYXMgYng9L2hvbWUvYW1uZXNpYS9ieC1saW51eC14NjQtcXJjb2RlCmFtbmVzaWFAYW1uZXNpYTp+JAoKMSkgQmFzZTU4IGFkZHJlc3MgaXMgdmFsaWQgZm9yIGFsbCBCVEMvQkNIL0JTVgoKMS4xKSBiYXNlNTggYWRkcmVzcyBmcm9tIHRleHQKYW1uZXNpYUBhbW5lc2lhOn4kCmFtbmVzaWFAYW1uZXNpYTp+JCBieCBiYXNlMTYtZW5jb2RlICJzZW5kIDElIG9mIGhvdyBtdWNoIHlvdSdkIGRvbmF0ZSBmb3IgcHVibGlzaGluZyBpbiBibG9ja2NoYWluIGRpeSBtYW51YWwgZm9yIGJ1aWxkaW5nIHNtYXJ0IHJvY2tldCIgfCBieCByaXBlbWQxNjAgfCBieCBhZGRyZXNzLWVuY29kZQoxSlltaHFzNDgxMlI1TWU3ZkhVTm84ZGZjelp3ank4SDJkCmFtbmVzaWFAYW1uZXNpYTp+JAoKMS4yKSBiYXNlNTggYWRkcmVzcyB3aXRoIHRleHQKYmFzZTU4IGFscGhhYmV0ID0gZGlnaXRzIGV4Y2x1ZGluZyAiMCIgKyBsb3dlcmNhc2UgbGV0dGVycyBleGNsdWRpbmcgImwiICsgdXBwZXJjYXNlIGxldHRlcnMgZXhjbHVkaW5nICJJIiwgIk8iCnN0cmluZyBvZiAzMyBsZXR0ZXJzLCBzdGFydHMgd2l0aCAiMSIsIGxhc3QgNiBvciA3IHdpbGwgYmUgY2hhbmdlZCwgMjUgb3IgMjYgcmVtYWluIGZvciB0ZXh0CmFtbmVzaWFAYW1uZXNpYTp+JAphbW5lc2lhQGFtbmVzaWE6fiQgYnggYmFzZTU4LWRlY29kZSAxUHJjbnRIbXd5ZGFGb3JLaUxMQmFkR3V5eHh4eHh4eHgKMDAwNDUyOTFjNTZjM2RmMGZhYTdkNTA4ZDE3NjYwNzY2MTg3YmE0MjNmMTQ4ZmY3MTEKYW1uZXNpYUBhbW5lc2lhOn4kCnJlbW92ZSAyIGZpcnN0IGFuZCA4IGxhc3QgYW5kCmFtbmVzaWFAYW1uZXNpYTp+JAphbW5lc2lhQGFtbmVzaWE6fiQgYnggYWRkcmVzcy1lbmNvZGUgMDQ1MjkxYzU2YzNkZjBmYWE3ZDUwOGQxNzY2MDc2NjE4N2JhNDIzZgoxUHJjbnRIbXd5ZGFGb3JLaUxMQmFkR3V5eHh5czZVTHkKYW1uZXNpYUBhbW5lc2lhOn4kCgoyKSBCVEMgU2VnV2l0IGFkZHJlc3MgKGJlY2gzMikKCjIuMSkgc2Vnd2l0IGFkZHJlc3MgZnJvbSB0ZXh0CmFtbmVzaWFAYW1uZXNpYTp+JAphbW5lc2lhQGFtbmVzaWE6fiQgYnggYmFzZTE2LWVuY29kZSAnMC4wMDEgaG13eWRhIGZvciBwdWJsaXNoaW5nIHByaXZhdGUgaW5mb3JtYXRpb24gYWJvdXQgYmFkIGd1eScgfCBieCByaXBlbWQxNjAKZjdiYTlhZGEwNmM4MzQ1NjBlNDM5Y2ZiM2I1YzA1NGRiMTMyOTE0ZAphbW5lc2lhQGFtbmVzaWE6fiQKYW1uZXNpYUBhbW5lc2lhOn4kIHB5dGhvbjMKPj4+Cj4+PiBmcm9tIHNlZ3dpdF9hZGRyIGltcG9ydCBlbmNvZGUKPj4+Cj4+PiBwcmludChlbmNvZGUoJ2JjJywgMCwgYnl0ZWFycmF5LmZyb21oZXgoJ2Y3YmE5YWRhMDZjODM0NTYwZTQzOWNmYjNiNWMwNTRkYjEzMjkxNGQnKSkpCmJjMXE3N2FmNGtzeGVxNjl2cmpybm5hbmtocTlma2NuOXkyZDdoMHEzego+Pj4KCjIuMikgc2Vnd2l0IGFkZHJlc3Mgd2l0aCB0ZXh0CmJlY2gzMiBhbHBoYWJldCA9IGRpZ2l0cyBleGNsdWRpbmcgIjEiICsgbG93ZXJjYXNlIGxldHRlcnMgZXhjbHVkaW5nICJiIiwgImkiLCAibyIKc3RyaW5nIG9mIDMyIG9yIDUxIGxldHRlcnMKPj4+Cj4+PiBmcm9tIHNlZ3dpdF9hZGRyIGltcG9ydCBDSEFSU0VULCBjb252ZXJ0Yml0cywgZW5jb2RlCj4+Pgo+Pj4gYXJyYXkgPSBbQ0hBUlNFVC5maW5kKHgpIGZvciB4IGluICdwZXJteWxobXd5ZGFzZW5kZHIwbmVtc2d0MDZhZGd1eSddCj4+PiBwcmludChlbmNvZGUoJ2JjJywgMCwgY29udmVydGJpdHMoYXJyYXksIDUsIDgpKSkKYmMxcXBlcm15bGhtd3lkYXNlbmRkcjBuZW1zZ3QwNmFkZ3V5cmZmMnl6Cj4+Pgo+Pj4gYXJyYXkgPSBbQ0hBUlNFVC5maW5kKHgpIGZvciB4IGluICcwbmVwZXJjbnRobXd5ZGFmMHJkMHh5bmd3aDB3MHJrc2hlbHBzcHIwdGVjdHM2YWRndXknXQo+Pj4gcHJpbnQoZW5jb2RlKCdiYycsIDAsIGNvbnZlcnRiaXRzKGFycmF5LCA1LCA4KSkpCmJjMXEwbmVwZXJjbnRobXd5ZGFmMHJkMHh5bmd3aDB3MHJrc2hlbHBzcHIwdGVjdHM2YWRndXlxYzV4c2N6Cj4+Pgo+Pj4gZXhpdCgpCmFtbmVzaWFAYW1uZXNpYTp+JAoKMykgQkNIIG5ldyBhZGRyZXNzIGZvcm1hdCAoYWxzbyBiZWNoMzIpCgozLjEpIEJDSCBhZGRyZXNzIGZyb20gdGV4dCAtIGNvbnZlcnQgZnJvbSAxLjEKYW1uZXNpYUBhbW5lc2lhOn4kCmFtbmVzaWFAYW1uZXNpYTp+JCBjZCBjYXNoYWRkcmVzcy0xLjAuNS8KYW1uZXNpYUBhbW5lc2lhOn4vY2FzaGFkZHJlc3MtMS4wLjUkCmFtbmVzaWFAYW1uZXNpYTp+L2Nhc2hhZGRyZXNzLTEuMC41JCBweXRob24zCj4+Pgo+Pj4gZnJvbSBjYXNoYWRkcmVzcy5jb252ZXJ0IGltcG9ydCB0b19jYXNoX2FkZHJlc3MKPj4+Cj4+PiBwcmludCh0b19jYXNoX2FkZHJlc3MoJzFKWW1ocXM0ODEyUjVNZTdmSFVObzhkZmN6WndqeThIMmQnKSkKYml0Y29pbmNhc2g6cXJxOGNrZGRhNnJ0aGt4NXhmOWFtMnFjemY3YXZ5ZmdmZ2pqNmhlMDI0Cj4+PgoKMy4yKSBCQ0ggYWRkcmVzcyB3aXRoIHRleHQKYmVjaDMyIGFscGhhYmV0IHNlZSAyLjIKc3RyaW5nIG9mIDM0IGxldHRlcnMsIHN0YXJ0cyB3aXRoICJxcSIsIGVuZHMgd2l0aCAicSIsIDMxIHJlbWFpbiBmb3IgdGV4dAo+Pj4KPj4+IGZyb20gY2Fz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";
    constexpr static auto pattern = ctll::fixed_string {"^(?:[A-Za-z0-9+/]{4})*(?:[A-Za-z0-9+/]{2}==|[A-Za-z0-9+/]{3}=|[A-Za-z0-9+/]{4})$"};
    std::cout << ctre::match<pattern> (b64_string) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
