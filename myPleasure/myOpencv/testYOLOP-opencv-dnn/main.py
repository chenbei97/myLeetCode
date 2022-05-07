import argparse
import cv2
from YOLO import yolop
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--imgpath", type=str, default='images/1.jpg', help="image path")
    parser.add_argument('--confThreshold', default=0.25, type=float, help='class confidence')
    parser.add_argument('--nmsThreshold', default=0.45, type=float, help='nms iou thresh')
    parser.add_argument('--objThreshold', default=0.5, type=float, help='object confidence')
    args = parser.parse_args()
    print(args)

    yolonet = yolop(confThreshold=args.confThreshold, nmsThreshold=args.nmsThreshold, objThreshold=args.objThreshold)
    srcimg = cv2.imread(args.imgpath)
    outimg = yolonet.detect(srcimg)

    winName = 'Deep learning object detection in OpenCV'
    cv2.namedWindow(winName, 0)
    cv2.imshow(winName, outimg)
    cv2.waitKey(0)
    cv2.destroyAllWindows()