static Janet cfun_rlViewport(int32_t argc, Janet *argv) {
    janet_fixarity(argc, 4);
    int posX = janet_getinteger(argv, 0);
    int posY = janet_getinteger(argv, 1);
    int width = janet_getinteger(argv, 2);
    int height = janet_getinteger(argv, 3);
    rlViewport(posX, posY, width, height);
    return janet_wrap_nil();
}

static JanetReg matrix_cfuns[] = {
    {"rl-viewport", cfun_rlViewport, NULL},
    {NULL, NULL, NULL}
};
