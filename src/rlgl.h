static Janet cfun_rlViewport(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 4);
  int posX = janet_getinteger(argv, 0);
  int posY = janet_getinteger(argv, 1);
  int width = janet_getinteger(argv, 2);
  int height = janet_getinteger(argv, 3);
  rlViewport(posX, posY, width, height);
  return janet_wrap_nil();
}

static Janet cfun_rlglDraw(int32_t argc, Janet *argv) {
  (void) argv;
  janet_fixarity(argc, 0);
  rlglDraw();
  return janet_wrap_nil();
}

static Janet cfun_rlEnableScissorTest(int32_t argc, Janet *argv) {
  (void) argv;
  janet_fixarity(argc, 0);
  rlEnableScissorTest();
  return janet_wrap_nil();
}

static Janet cfun_rlScissor(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 4);
  int posX = janet_getinteger(argv, 0);
  int posY = janet_getinteger(argv, 1);
  int width = janet_getinteger(argv, 2);
  int height = janet_getinteger(argv, 3);
  rlScissor(posX, posY, width, height);
  return janet_wrap_nil();
}

static JanetReg rlgl_cfuns[] = {
				{"rl-viewport", cfun_rlViewport, NULL},
				{"rlgl-draw", cfun_rlglDraw, NULL},
				{"rl-enable-scissor-test", cfun_rlEnableScissorTest, NULL},
				{"rl-scissor", cfun_rlScissor, NULL},
				{NULL, NULL, NULL}
};
