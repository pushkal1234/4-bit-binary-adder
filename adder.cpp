void adder(bool a, bool b, bool cin, bool *sum, bool *cout) {

	*sum = a^b^cin;

	*cout = (a&&b)||(b&&cin)||(a&&cin);
}



void fourbit_adder(
		bool  a0,
		bool  a1,
		bool  a2,
		bool  a3,

		bool  b0,
		bool  b1,
		bool  b2,
		bool  b3,

		bool *s0,
		bool *s1,
		bool *s2,
		bool *s3,

		bool *c
		) {

#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS INTERFACE ap_none port=a0
#pragma HLS INTERFACE ap_none port=a1
#pragma HLS INTERFACE ap_none port=a2
#pragma HLS INTERFACE ap_none port=a3

#pragma HLS INTERFACE ap_none port=b0
#pragma HLS INTERFACE ap_none port=b1
#pragma HLS INTERFACE ap_none port=b2
#pragma HLS INTERFACE ap_none port=b3

#pragma HLS INTERFACE ap_none port=s0
#pragma HLS INTERFACE ap_none port=s1
#pragma HLS INTERFACE ap_none port=s2
#pragma HLS INTERFACE ap_none port=s3

#pragma HLS INTERFACE ap_none port=c

	bool c0, c1, c2, c3, c4;

	adder(a0, b0,  0, s0, &c0);
	adder(a1, b1, c0, s1, &c1);
	adder(a2, b2, c1, s2, &c2);
	adder(a3, b3, c2, s3, &c3);

	*c = c3;
}
