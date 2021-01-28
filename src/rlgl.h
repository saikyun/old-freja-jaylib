static Janet cfun_rlViewport(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 4);
  int posX = janet_getinteger(argv, 0);
  int posY = janet_getinteger(argv, 1);
  int width = janet_getinteger(argv, 2);
  int height = janet_getinteger(argv, 3);
  rlViewport(posX, posY, width, height);
  return janet_wrap_nil();
}

static const KeyDef rl_flag_defs[] = {
				      {"rl-modelview", RL_MODELVIEW},
				      {"rl-projection", RL_PROJECTION},
};


static Janet cfun_rlMatrixMode(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 1);
  const uint8_t *arg_flag = janet_getkeyword(argv, 0);
  int flag = 0;
  for (unsigned j = 0; j < (sizeof(rl_flag_defs) / sizeof(KeyDef)); j++) {
    if (!janet_cstrcmp(arg_flag, rl_flag_defs[j].name))
      {
	flag = rl_flag_defs[j].key;
	break;
      }
  }

  if (0 == flag) {
    JanetArray *available = janet_array(0);
    for (unsigned j = 0; j < (sizeof(flag_defs) / sizeof(KeyDef)); j++) {
      janet_array_push(available, janet_ckeywordv(flag_defs[j].name));
    }
    janet_panicf("unknown flag %v - available flags are %p", arg_flag,
		 janet_wrap_array(available));
  }
  
  rlMatrixMode(flag);
  return janet_wrap_nil();
}

static Janet cfun_rlLoadIdentity(int32_t argc, Janet *argv) {
  (void) argv;
  janet_fixarity(argc, 0);
  rlLoadIdentity();
  return janet_wrap_nil();
}

static Janet cfun_rlOrtho(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 6);
  int left = (float) janet_getnumber(argv, 0);
  int right = (float) janet_getnumber(argv, 1);
  int bottom = (float) janet_getnumber(argv, 2);
  int top = (float) janet_getnumber(argv, 3);
  int znear = (float) janet_getnumber(argv, 4);
  int zfar = (float) janet_getnumber(argv, 5);
  rlOrtho(left, right, bottom, top, znear, zfar);
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
				{"rl-matrix-mode", cfun_rlMatrixMode, NULL},
				{"rl-ortho", cfun_rlOrtho, NULL},
				{"rl-load-identity", cfun_rlLoadIdentity, NULL},
				{"rlgl-draw", cfun_rlglDraw, NULL},
				{"rl-enable-scissor-test", cfun_rlEnableScissorTest, NULL},
				{"rl-scissor", cfun_rlScissor, NULL},
				{NULL, NULL, NULL}
};
