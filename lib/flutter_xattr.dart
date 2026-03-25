import 'dart:ffi';

import 'package:ffi/ffi.dart';

import 'flutter_xattr_bindings_generated.dart' as bindings;

class Xattr {
  // get an xattr attribute on a file.
  static String getFileAttribute(String path, String attribute) {
    final filePathUtf8 = path.toNativeUtf8().cast<Char>();
    final attributeUtf8 = attribute.toNativeUtf8().cast<Char>();
    final attributeValueUtf8 = bindings.get_attribute(
      filePathUtf8,
      attributeUtf8,
    );
    final attributeValue = attributeValueUtf8.cast<Utf8>().toDartString();
    calloc.free(filePathUtf8);
    calloc.free(attributeUtf8);
    if (attributeValue.isNotEmpty) {
      bindings.free_string(attributeValueUtf8);
    }
    return attributeValue;
  }
}
