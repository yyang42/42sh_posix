#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer_arexp(num01, "a+=b-=c*=d/=e%=f|=g^=h&=i<<=j>>=l=42",
		"a_+=_b_-=_c_*=_d_/=_e_%=_f_|=_g_^=_h_&=_i_<<=_j_>>=_l_=_42", false);
mt_test_tokenizer_arexp(num02, "a=b<=c?d>=e?f!=g:h==i:j&k",
		"a_=_b_<=_c_?_d_>=_e_?_f_!=_g_:_h_==_i_:_j_&_k", false);
mt_test_tokenizer_arexp(num03, "a=b?c:d,e=f?g:h",
		"a_=_b_?_c_:_d_,_e_=_f_?_g_:_h", false);
mt_test_tokenizer_arexp(num04, "((((64#aze__))))",
		"(_(_(_(_64#aze___)_)_)_)", false);
mt_test_tokenizer_arexp(num05, "+-*/%>>><<<===",
		"+_-_*_/_%_>>_>_<<_<=_==", false);
mt_test_tokenizer_arexp(num06, "123    123    123", "123_123_123", false);
mt_test_tokenizer_arexp(num07, "< <= > >= == != ! ~",
		"<_<=_>_>=_==_!=_!_~", false);
mt_test_tokenizer_arexp(num08, "~~+!-(-42)", "~_~_+_!_-_(_-_42_)", false);

void    suite_tokenizer_arexp_middle(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num01);
    SUITE_ADD_TEST(suite, test_num02);
    SUITE_ADD_TEST(suite, test_num03);
    SUITE_ADD_TEST(suite, test_num04);
    SUITE_ADD_TEST(suite, test_num05);
    SUITE_ADD_TEST(suite, test_num06);
    SUITE_ADD_TEST(suite, test_num07);
    SUITE_ADD_TEST(suite, test_num08);
}
