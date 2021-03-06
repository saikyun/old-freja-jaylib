(use ../build/jaylib)

(set-config-flags :msaa-4x-hint)
(set-config-flags :window-resizable)

(init-window 800 450 "Test Game")
(set-target-fps 60)

(def font (load-font-ex "test/Monaco.ttf" 24 (string/bytes " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHI\nJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmn\nopqrstuvwxyz{|}~¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓ\nÔÕÖ×ØÙÚÛÜÝÞßàáâãäååæçèéêëìíîïðñòóôõö÷\nøùúûüýþÿ")))

(while (not (window-should-close))
  
  (def w (* 2 (get-screen-width)))
  (def h (* 2 (get-screen-height)))
  
  (rl-viewport 0 0 w h)      
  
  (rl-matrix-mode :rl-projection)          
  (rl-load-identity)          
  (rl-ortho 0.0 (* 2 w) (* 2 h) 0.0 0.0 1.0)         # Recalculate internal projection matrix          
  (rl-matrix-mode :rl-modelview) # Enable internal modelview matrix          
  (rl-load-identity)   
  
  
  
  (begin-drawing)
  (clear-background :white)
  (draw-text-ex font "(def w (* 2 (get-screen-width)))" [10 10] 24 1 :black)
  (end-drawing))

(close-window)


(comment
 
 (comment
  (def lenna (load-image-1 "test/lenna.png"))
  (image-dither lenna 4 4 4 4)
  (def lenna-t (load-texture-from-image lenna))
  (gen-texture-mipmaps lenna-t))
 (comment
  (def c (camera-3d :target [0 3 0]
                    :up [0 1 0]
                    :fovy 60
                    :type :perspective
            :position [6 3 6]))
  
  (set-camera-mode c :orbital))
 
 
 (while (not (window-should-close))
   # (update-camera c)
   
   (def w (* 2 (get-screen-width)))   
   (def h (* 2 (get-screen-height)))
   
   (print "wh " w " " h)
   
   (comment
    (rl-viewport 0 0 w h)
    
    (rl-matrix-mode :rl-projection)    
    (rl-load-identity)    
    (rl-ortho 0.0 w h 0.0 0.0 1.0)         # Recalculate internal projection matrix    
    (rl-matrix-mode :rl-modelview) # Enable internal modelview matrix    
    (rl-load-identity))             # Reset internal modelview matrix
   
   
   (begin-drawing)
   
   (clear-background :white)
   
   #  (rl-viewport 0 0 (* 2 (get-screen-width)) (* 2 (get-screen-height)))
   
   (comment
    (rlgl-draw)
    (rl-enable-scissor-test)
    #(pp    (get-screen-scale))
    (rl-scissor (* 2 20)
                (* 2 (- (get-screen-height) (+ 40 500)))
                (* 2 500) (* 2 500)))
   
   #(clear-background :black)  
   
   #  (begin-mode-3d c)
   #  (draw-gizmo [0 0 0])
   (comment  (each x [1 2.4 3.3 3.9 4.4 5]
               (def s (/ 2 x))
               (draw-cube-texture lenna-t [2 x 2] s s s :white))
             (end-mode-3d))
   
   (comment
    (end-scissor-mode))
   
   (draw-text-ex font "Loaded Font" [10 10] 24 1 :black)
   
   (end-drawing))
 )
