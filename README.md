# flutter_xattr

Get xattr file attributes on linux.

## Usage

```dart
import 'package:flutter_xattr/flutter_xattr.dart';

var hostPath = Xattr.getFileAttribute(
    campaignFile.path,
    "user.attribute-name",
);
```
