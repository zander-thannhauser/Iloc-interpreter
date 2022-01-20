
#define LAMBDA_HELPER(name, params, statements) \
	({ void name params statements name; })

#define LAMBDA(params, statements) \
	LAMBDA_HELPER(lambda_##__COUNTER__, params, statements)

