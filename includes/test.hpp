
#include <functional>
template <class A, class B, class C = std::less<A> >
class fun
{
	public:
	fun() {};
	bool fun2(A a, B b, C cmp = C())
	{
		return cmp(a, b);
	}
};
