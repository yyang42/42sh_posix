fn () if true
then
	echo true_text
else
	echo else_text
fi
fn

fn () if false
then
	echo true_text
else
	echo else_text
fi
fn
